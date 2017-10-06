$NetBSD: patch-gold_options.h,v 1.2 2016/02/03 19:56:34 jperkin Exp $

 The NetBSD and OpenBSD real-time linkers do not understand DT_RUNPATH
 or DT_INIT_ARRAY.  The current gold defaults are not suitable for them.
 The last couple of DragonFly and FreeBSD releases do support these tags.

