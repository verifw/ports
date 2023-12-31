--- cmake/FindSuiteSparse.cmake.orig	2022-03-28 14:02:35 UTC
+++ cmake/FindSuiteSparse.cmake
@@ -394,26 +394,36 @@ if (TARGET SuiteSparse::Config)
   else (NOT EXISTS ${SuiteSparse_VERSION_FILE})
     file(READ ${SuiteSparse_VERSION_FILE} Config_CONTENTS)
 
-    string(REGEX MATCH "#define SUITESPARSE_MAIN_VERSION [0-9]+"
-      SuiteSparse_VERSION_MAJOR "${Config_CONTENTS}")
-    string(REGEX REPLACE "#define SUITESPARSE_MAIN_VERSION ([0-9]+)" "\\1"
-      SuiteSparse_VERSION_MAJOR "${SuiteSparse_VERSION_MAJOR}")
+    string(REGEX MATCH "#define SUITESPARSE_MAIN_VERSION[ \t]+([0-9]+)"
+      SuiteSparse_VERSION_LINE "${Config_CONTENTS}")
+    set (SuiteSparse_VERSION_MAJOR ${CMAKE_MATCH_1})
 
-    string(REGEX MATCH "#define SUITESPARSE_SUB_VERSION [0-9]+"
-      SuiteSparse_VERSION_MINOR "${Config_CONTENTS}")
-    string(REGEX REPLACE "#define SUITESPARSE_SUB_VERSION ([0-9]+)" "\\1"
-      SuiteSparse_VERSION_MINOR "${SuiteSparse_VERSION_MINOR}")
+    string(REGEX MATCH "#define SUITESPARSE_SUB_VERSION[ \t]+([0-9]+)"
+      SuiteSparse_VERSION_LINE "${Config_CONTENTS}")
+    set (SuiteSparse_VERSION_MINOR ${CMAKE_MATCH_1})
 
-    string(REGEX MATCH "#define SUITESPARSE_SUBSUB_VERSION [0-9]+"
-      SuiteSparse_VERSION_PATCH "${Config_CONTENTS}")
-    string(REGEX REPLACE "#define SUITESPARSE_SUBSUB_VERSION ([0-9]+)" "\\1"
-      SuiteSparse_VERSION_PATCH "${SuiteSparse_VERSION_PATCH}")
+    string(REGEX MATCH "#define SUITESPARSE_SUBSUB_VERSION[ \t]+([0-9]+)"
+      SuiteSparse_VERSION_LINE "${Config_CONTENTS}")
+    set (SuiteSparse_VERSION_PATCH ${CMAKE_MATCH_1})
 
+    unset (SuiteSparse_VERSION_LINE)
+
     # This is on a single line s/t CMake does not interpret it as a list of
     # elements and insert ';' separators which would result in 4.;2.;1 nonsense.
     set(SuiteSparse_VERSION
       "${SuiteSparse_VERSION_MAJOR}.${SuiteSparse_VERSION_MINOR}.${SuiteSparse_VERSION_PATCH}")
-    set(SuiteSparse_VERSION_COMPONENTS 3)
+
+    if (SuiteSparse_VERSION MATCHES "[0-9]+\\.[0-9]+\\.[0-9]+")
+      set(SuiteSparse_VERSION_COMPONENTS 3)
+    else (SuiteSparse_VERSION MATCHES "[0-9]+\\.[0-9]+\\.[0-9]+")
+      message (WARNING "Could not parse SuiteSparse_config.h: SuiteSparse "
+        "version will not be available")
+
+      unset (SuiteSparse_VERSION)
+      unset (SuiteSparse_VERSION_MAJOR)
+      unset (SuiteSparse_VERSION_MINOR)
+      unset (SuiteSparse_VERSION_PATCH)
+    endif (SuiteSparse_VERSION MATCHES "[0-9]+\\.[0-9]+\\.[0-9]+")
   endif (NOT EXISTS ${SuiteSparse_VERSION_FILE})
 endif (TARGET SuiteSparse::Config)
 
