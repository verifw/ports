PORTNAME=	aioquic
PORTVERSION=	0.9.21
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC and HTTP/3
WWW=		https://github.com/aiortc/aioquic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylsqpack>=0.3.3<0.4.0:www/py-pylsqpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=21,1:security/py-openssl@${PY_FLAVOR}

USES=		python ssl
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
