$NetBSD: patch-lib_worker.c,v 1.3 2017/05/24 07:42:39 manu Exp $

64bit time_t workaround

--- lib/worker.c.orig	2018-08-16 19:10:12.000000000 +0000
+++ lib/worker.c
@@ -304,8 +304,8 @@ int finish_job(child_process *cp, int re
 		kvvec_addkv_wlen(&resp, kv->key, kv->key_len, kv->value, kv->value_len);
 	}
 	kvvec_addkv(&resp, "wait_status", mkstr("%d", cp->ret));
-	kvvec_add_tv(&resp, "start", cp->ei->start);
-	kvvec_add_tv(&resp, "stop", cp->ei->stop);
+	kvvec_add_tv(&resp, "start", (unsigned long)cp->ei->start);
+	kvvec_add_tv(&resp, "stop", (unsigned long)cp->ei->stop);
 	kvvec_addkv(&resp, "runtime", mkstr("%f", cp->ei->runtime));
 	if (!reason) {
 		/* child exited nicely */
