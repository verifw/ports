PORTNAME=	asttokens
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Annotate AST trees with source code positions
WWW=		https://pypi.org/project/asttokens/ \
		https://github.com/gristlabs/asttokens

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid253>=0:devel/py-astroid253@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
TEST_ARGS=	--ignore=tests/testdata
NO_ARCH=	yes

.include <bsd.port.mk>
