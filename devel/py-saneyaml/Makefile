PORTNAME=	saneyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dump readable YAML and load safely any YAML data
WWW=		https://github.com/nexB/saneyaml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	nexB

NO_ARCH=	yes

.include <bsd.port.mk>
