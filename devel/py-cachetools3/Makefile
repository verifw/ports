PORTNAME=	cachetools
PORTVERSION=	3.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensible memoizing collections and decorators
WWW=		https://github.com/tkem/cachetools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# cachetools 4.0.0+ requires Python 3.5+
PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
