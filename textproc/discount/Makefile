# $NetBSD: Makefile,v 1.2 2015/11/04 01:10:18 leot Exp $
#

DISTNAME=	discount-2.1.8a
CATEGORIES=	textproc
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/discount/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=	Markdown C implementation
LICENSE=	modified-bsd

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--execdir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-all-features

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
