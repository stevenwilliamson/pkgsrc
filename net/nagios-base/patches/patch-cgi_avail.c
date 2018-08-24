$NetBSD: patch-cgi_avail.c,v 1.5 2017/05/24 07:42:39 manu Exp $

64bit time_t workaround

--- cgi/avail.c.orig	2018-08-16 19:10:12.000000000 +0000
+++ cgi/avail.c
@@ -377,10 +377,10 @@ int main(int argc, char **argv) {
 				host_report_url("all", "View Availability Report For All Hosts");
 				printf("<BR>\n");
 #ifdef USE_TRENDS
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&assumeinitialstates=%s&includesoftstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&assumeinitialstates=%s&includesoftstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
 #endif
 #ifdef USE_HISTOGRAM
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
 				printf("<a href='%s?host=%s'>View Status Detail For This Host</a><BR>\n", STATUS_CGI, url_encode(host_name));
 				printf("<a href='%s?host=%s'>View Alert History For This Host</a><BR>\n", HISTORY_CGI, url_encode(host_name));
@@ -393,11 +393,11 @@ int main(int argc, char **argv) {
 				printf("<BR>\n");
 #ifdef USE_TRENDS
 				printf("<a href='%s?host=%s", TRENDS_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
 #endif
 #ifdef USE_HISTOGRAM
 				printf("<a href='%s?host=%s", HISTOGRAM_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
 				printf("<A HREF='%s?host=%s&", HISTORY_CGI, url_encode(host_name));
 				printf("service=%s'>View Alert History For This Service</A><BR>\n", url_encode(svc_description));
@@ -2264,7 +2264,7 @@ void compute_subject_downtime_times(time
 	archived_state *last        = NULL;
 
 #ifdef DEBUG2
-	printf("<P><b>ENTERING COMPUTE_SUBJECT_DOWNTIME_TIMES: start=%lu, end=%lu, t1=%lu, t2=%lu </b></P>", start_time, end_time, t1, t2);
+	printf("<P><b>ENTERING COMPUTE_SUBJECT_DOWNTIME_TIMES: start=%lu, end=%lu, t1=%lu, t2=%lu </b></P>", start_time, end_time, (unsigned long)t1, (unsigned long)t2);
 #endif
 
 	/* times are weird, so bail out... */
@@ -4310,7 +4310,7 @@ void display_host_availability(void)
 #ifdef USE_TRENDS
 			printf("<p align='center'>\n");
 			printf("<a href='%s?host=%s", TRENDS_CGI, url_encode(host_name));
-			printf("&t1=%lu&t2=%lu&includesoftstates=%s", t1, t2, (include_soft_states == TRUE) ? "yes" : "no");
+			printf("&t1=%lu&t2=%lu&includesoftstates=%s", (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no");
 			printf("&assumestateretention=%s&assumeinitialstates=%s", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no");
 			printf("&assumestatesduringnotrunning=%s&initialassumedhoststate=%d", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state);
 			printf("&backtrack=%d'>", backtrack_archives);
@@ -4319,7 +4319,7 @@ void display_host_availability(void)
 #else
 			printf("<img src='%s?createimage&smallimage&host=%s", LEGACY_TRENDS_CGI, url_encode(host_name));
 #endif
-			printf("&t1=%lu&t2=%lu&includesoftstates=%s", t1, t2, (include_soft_states == TRUE) ? "yes" : "no");
+			printf("&t1=%lu&t2=%lu&includesoftstates=%s", (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no");
 			printf("&assumestateretention=%s&assumeinitialstates=%s", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no");
 			printf("&assumestatesduringnotrunning=%s&initialassumedhoststate=%d", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state);
 			printf("&backtrack=%d'", backtrack_archives);
@@ -4951,7 +4951,7 @@ void display_service_availability(void)
 #ifdef USE_TRENDS
 			printf("<p align='center'>\n");
 			printf("<a href='%s?host=%s", TRENDS_CGI, url_encode(host_name));
-			printf("&service=%s&t1=%lu&t2=%lu&includesoftstates=%s", url_encode(svc_description), t1, t2, (include_soft_states == TRUE) ? "yes" : "no");
+			printf("&service=%s&t1=%lu&t2=%lu&includesoftstates=%s", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no");
 			printf("&assumestateretention=%s&assumeinitialstates=%s", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no");
 			printf("&assumestatesduringnotrunning=%s&initialassumedservicestate=%d", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state);
 			printf("&backtrack=%d'>", backtrack_archives);
@@ -4960,7 +4960,7 @@ void display_service_availability(void)
 #else
 			printf("<img src='%s?createimage&smallimage&host=%s", LEGACY_TRENDS_CGI, url_encode(host_name));
 #endif
-			printf("&service=%s&t1=%lu&t2=%lu", url_encode(svc_description), t1, t2);
+			printf("&service=%s&t1=%lu&t2=%lu", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2);
 			printf("&includesoftstates=%s&assumestateretention=%s", (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no");
 			printf("&assumeinitialstates=%s&assumestatesduringnotrunning=%s", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no");
 			printf("&initialassumedservicestate=%d&backtrack=%d'", initial_assumed_service_state, backtrack_archives);
@@ -5296,7 +5296,7 @@ void host_report_url(const char *hn, con
 
 	printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(hn));
 	printf("&show_log_entries");
-	printf("&t1=%lu&t2=%lu", t1, t2);
+	printf("&t1=%lu&t2=%lu", (unsigned long)t1, (unsigned long)t2);
 	printf("&backtrack=%d", backtrack_archives);
 	printf("&assumestateretention=%s", (assume_state_retention == TRUE) ? "yes" : "no");
 	printf("&assumeinitialstates=%s", (assume_initial_states == TRUE) ? "yes" : "no");
@@ -5320,7 +5320,7 @@ void service_report_url(const char *hn,
 
 	printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(hn));
 	printf("&service=%s", url_encode(sd));
-	printf("&t1=%lu&t2=%lu", t1, t2);
+	printf("&t1=%lu&t2=%lu", (unsigned long)t1, (unsigned long)t2);
 	printf("&backtrack=%d", backtrack_archives);
 	printf("&assumestateretention=%s", (assume_state_retention == TRUE) ? "yes" : "no");
 	printf("&assumeinitialstates=%s", (assume_initial_states == TRUE) ? "yes" : "no");
