$NetBSD: patch-gold_options.h,v 1.2 2016/02/03 19:56:34 jperkin Exp $

 The NetBSD and OpenBSD real-time linkers do not understand DT_RUNPATH
 or DT_INIT_ARRAY.  The current gold defaults are not suitable for them.
 The last couple of DragonFly and FreeBSD releases do support these tags.

--- gold/options.h.orig	2017-09-19 13:55:52.000000000 +0000
+++ gold/options.h
@@ -768,9 +768,15 @@ class General_options
 	      N_("Output cross reference table"),
 	      N_("Do not output cross reference table"));
 
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', false,
+             N_("Use DT_INIT_ARRAY for all constructors"),
+             N_("Handle constructors as directed by compiler (default)"));
+#else
   DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', true,
 	      N_("Use DT_INIT_ARRAY for all constructors"),
 	      N_("Handle constructors as directed by compiler"));
+#endif
 
   // d
 
