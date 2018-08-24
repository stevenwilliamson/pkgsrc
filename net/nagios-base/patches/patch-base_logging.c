$NetBSD$

64bit time_t workaround

--- base/logging.c.orig	2018-08-16 19:10:12.000000000 +0000
+++ base/logging.c
@@ -533,7 +533,7 @@ int log_debug_info(int level, int verbos
 
 	/* write the timestamp */
 	gettimeofday(&current_time, NULL);
-	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", current_time.tv_sec, current_time.tv_usec, level, verbosity, (unsigned long)getpid());
+	fprintf(debug_file_fp, "[%lu.%06lu] [%03d.%d] [pid=%lu] ", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_usec, level, verbosity, (unsigned long)getpid());
 
 	/* write the data */
 	va_start(ap, fmt);
