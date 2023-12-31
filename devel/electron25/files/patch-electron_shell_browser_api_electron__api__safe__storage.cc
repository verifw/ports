--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2023-08-09 14:05:20 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -23,7 +23,7 @@ static const char* kEncryptionVersionPrefixV11 = "v11"
 static bool use_password_v10 = false;
 
 bool IsEncryptionAvailable() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calling IsEncryptionAvailable() before the app is ready results in a crash
   // on Linux.
   // Refs: https://github.com/electron/electron/issues/32206.
@@ -42,7 +42,7 @@ void SetUsePasswordV10(bool use) {
   use_password_v10 = use;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetSelectedLinuxBackend() {
   if (!Browser::Get()->is_ready())
     return "unknown";
@@ -143,7 +143,7 @@ void Initialize(v8::Local<v8::Object> exports,
   dict.SetMethod("decryptString", &electron::safestorage::DecryptString);
   dict.SetMethod("setUsePlainTextEncryption",
                  &electron::safestorage::SetUsePasswordV10);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dict.SetMethod("getSelectedStorageBackend",
                  &electron::safestorage::GetSelectedLinuxBackend);
 #endif
