# $NetBSD: Makefile,v 1.60 2017/09/06 09:03:03 wiz Exp $

DISTNAME=	wmbiff-0.4.26
PKGREVISION=	25
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wmbiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/wmbiff/
COMMENT=	WindowMaker xbuffy-like "mail-checker"

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

EX_DIR=		${PREFIX}/share/examples/wmbiff

INSTALLATION_DIRS+=	${EX_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${DESTDIR}${EX_DIR}

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
