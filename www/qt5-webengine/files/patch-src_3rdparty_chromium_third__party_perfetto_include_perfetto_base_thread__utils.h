--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -35,6 +35,9 @@
 #else
 #include <pthread.h>
 #endif
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#include <pthread_np.h>
+#endif
 
 namespace perfetto {
 namespace base {
@@ -43,6 +46,11 @@ inline PlatformThreadId GetThreadId() {
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+using PlatformThreadId = pid_t;
+inline PlatformThreadId GetThreadId() {
+  return pthread_getthreadid_np();
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;
