PORTNAME=	wsme
PORTVERSION=	0.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSME-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplify the writing of REST APIs
WWW=		https://opendev.org/x/wsme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.12:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplegeneric>=0:devel/py-simplegeneric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.8.0:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
