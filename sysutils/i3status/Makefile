# $NetBSD: Makefile,v 1.6 2017/09/08 02:38:43 ryoon Exp $
#

DISTNAME=	i3status-2.10
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://i3wm.org/i3status/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/i3status/
COMMENT=	Small program for generating a status bar
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/i3status.conf ${PKG_SYSCONFDIR}/i3status.conf

BUILD_DEFS+=	VARBASE

MAKE_ENV+=	MANDIR=${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	DEBUG=0

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		i3status.conf
SUBST_SED.fix-paths+=		-e 's,/var,${VARBASE},g'

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
