# $NetBSD: Makefile,v 1.12 2017/08/31 09:27:44 adam Exp $

DISTNAME=	xlrd-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xlrd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lexicon.net/sjmachin/xlrd.htm
COMMENT=	Python library to extract data from Microsoft Excel spreadsheet files
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} runxlrd.py runxlrd${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
