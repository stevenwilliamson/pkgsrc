$NetBSD: patch-bfd_elf32-arm.c,v 1.1 2016/01/30 22:15:11 ryoon Exp $

Resolve popcount(3) conflict on NetBSD

--- bfd/elf32-arm.c.orig	2017-07-10 09:54:41.000000000 +0000
+++ bfd/elf32-arm.c
@@ -3258,6 +3258,7 @@ elf32_arm_popcount (unsigned int mask)
   return sum;
 #endif
 }
+#endif
 
 /* Create an entry in an ARM ELF linker hash table.  */
 
