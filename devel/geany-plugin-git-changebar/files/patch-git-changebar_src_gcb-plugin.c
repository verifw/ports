--- git-changebar/src/gcb-plugin.c.orig	2021-09-19 13:29:36 UTC
+++ git-changebar/src/gcb-plugin.c
@@ -32,11 +32,19 @@
 #include <geany.h>
 #include <document.h>
 
-#if ! defined (LIBGIT2_VER_MINOR) || ( (LIBGIT2_VER_MAJOR == 0) && (LIBGIT2_VER_MINOR < 22) )
+#ifdef LIBGIT2_VER_MINOR
+# define CHECK_LIBGIT2_VERSION(MAJOR, MINOR) \
+  ((LIBGIT2_VER_MAJOR == (MAJOR) && LIBGIT2_VER_MINOR >= (MINOR)) || \
+   LIBGIT2_VER_MAJOR > (MAJOR))
+#else /* ! defined(LIBGIT2_VER_MINOR) */
+# define CHECK_LIBGIT2_VERSION(MAJOR, MINOR) 0
+#endif
+
+#if ! CHECK_LIBGIT2_VERSION(0, 22)
 # define git_libgit2_init     git_threads_init
 # define git_libgit2_shutdown git_threads_shutdown
 #endif
-#if ! defined (LIBGIT2_VER_MINOR) || ( (LIBGIT2_VER_MAJOR == 0) && (LIBGIT2_VER_MINOR < 23) )
+#if ! CHECK_LIBGIT2_VERSION(0, 23)
 /* 0.23 added @p binary_cb */
 # define git_diff_buffers(old_buffer, old_len, old_as_path, \
                           new_buffer, new_len, new_as_path, options, \
@@ -45,7 +53,7 @@
                     new_buffer, new_len, new_as_path, options, \
                     file_cb, hunk_cb, line_cb, payload)
 #endif
-#if ! defined (LIBGIT2_VER_MINOR) || ( (LIBGIT2_VER_MAJOR == 0) && (LIBGIT2_VER_MINOR < 28) )
+#if ! CHECK_LIBGIT2_VERSION(0, 28)
 # define git_buf_dispose  git_buf_free
 # define git_error_last   giterr_last
 #endif
@@ -211,30 +219,19 @@ static const struct {
 };
 
 
-/* workaround https://github.com/libgit2/libgit2/pull/3187 */
-static int
-gcb_git_buf_grow (git_buf  *buf,
-                  size_t    target_size)
-{
-  if (buf->asize == 0) {
-    if (target_size == 0) {
-      target_size = buf->size;
-    }
-    if ((target_size & 7) == 0) {
-      target_size++;
-    }
-  }
-  return git_buf_grow (buf, target_size);
-}
-#define git_buf_grow gcb_git_buf_grow
-
 static void
 buf_zero (git_buf *buf)
 {
   if (buf) {
     buf->ptr = NULL;
     buf->size = 0;
+#if ! CHECK_LIBGIT2_VERSION(1, 4)
     buf->asize = 0;
+#else
+    /* we don't really need this field, but the documentation states that all
+     * fields should be set to 0, so fill it as well */
+    buf->reserved = 0;
+#endif
   }
 }
 
@@ -248,6 +245,52 @@ clear_cached_blob_contents (void)
   G_blob_contents_tag = 0;
 }
 
+/* similar to old git_blob_filtered_content() but makes sure the caller owns
+ * the data in the output buffer -- and uses a boolean return */
+static gboolean
+get_blob_contents (git_buf     *out,
+                   git_blob    *blob,
+                   const char  *as_path,
+                   int          check_for_binary_data)
+{
+/* libgit2 1.4 changed buffer API quite a bit */
+#if ! CHECK_LIBGIT2_VERSION(1, 4)
+  gboolean success = TRUE;
+
+  if (git_blob_filtered_content (out, blob, as_path,
+                                 check_for_binary_data) != 0)
+    return FALSE;
+
+  /* Workaround for https://github.com/libgit2/libgit2/pull/3187
+   * We want to own the buffer, which git_buf_grow(buf, 0) was supposed to do,
+   * but there is a corner case where it doesn't do what it should and
+   * truncates the buffer contents, so we fix this manually. */
+  if (out->asize == 0) {
+    size_t target_size = out->size;
+    if ((target_size & 7) == 0) {
+      target_size++;
+    }
+    success = (git_buf_grow (out, target_size) == 0);
+  }
+
+  return success;
+#else /* libgit2 >= 1.4 */
+  /* Here we can assume we will always get a buffer we own (at least as of
+   * 2022-06-05 it is the case), so there's no need for a pendent to the
+   * previous git_buf_grow() shenanigans.
+   * This code path does the same as the older git_blob_filtered_content()
+   * but with non-deprecated API */
+  git_blob_filter_options opts = GIT_BLOB_FILTER_OPTIONS_INIT;
+
+  if (check_for_binary_data)
+    opts.flags |= GIT_BLOB_FILTER_CHECK_FOR_BINARY;
+  else
+    opts.flags &= ~GIT_BLOB_FILTER_CHECK_FOR_BINARY;
+
+  return git_blob_filter(out, blob, as_path, &opts) == 0;
+#endif
+}
+
 /* get the file blob for @relpath at HEAD */
 static gboolean
 repo_get_file_blob_contents (git_repository  *repo,
@@ -271,11 +314,8 @@ repo_get_file_blob_contents (git_repository  *repo,
           git_blob *blob;
           
           if (git_blob_lookup (&blob, repo, git_tree_entry_id (entry)) == 0) {
-            if (git_blob_filtered_content (contents, blob, relpath,
-                                           check_for_binary_data) == 0 &&
-                git_buf_grow (contents, 0) == 0) {
-              success = TRUE;
-            }
+            success = get_blob_contents (contents, blob, relpath,
+                                         check_for_binary_data);
             git_blob_free (blob);
           }
           git_tree_entry_free (entry);
