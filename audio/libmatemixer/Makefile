# $NetBSD: Makefile,v 1.6 2017/08/21 23:54:50 jmcneill Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatemixer-${VERSION}
PKGREVISION=	1
CATEGORIES=	audio

COMMENT=	MATE audio mixer

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
.endif

.include "../../mk/bsd.pkg.mk"
