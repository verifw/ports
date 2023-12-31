--- libcdi/src/namespace.c.orig	2023-04-16 12:23:50 UTC
+++ libcdi/src/namespace.c
@@ -99,11 +99,13 @@ static pthread_mutex_t namespaceMutex;
 static void
 namespaceInitialize(void)
 {
+#if defined(PTHREAD_MUTEXATTR)
   pthread_mutexattr_t ma;
   pthread_mutexattr_init(&ma);
   pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_RECURSIVE);
   pthread_mutex_init(&namespaceMutex, &ma);
   pthread_mutexattr_destroy(&ma);
+#endif
 }
 
 #define NAMESPACE_LOCK() pthread_mutex_lock(&namespaceMutex)
