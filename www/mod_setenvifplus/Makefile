PORTNAME=	mod_setenvifplus
PORTVERSION=	0.40
CATEGORIES=	www
MASTER_SITES=	SF/modsetenvifplus
EXTRACT_SUFX=	-src.tar.gz
DIST_SUBDIR=	apache2

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Allows setting environment variables based on request attributes
WWW=		http://modsetenvifplus.sourceforge.net/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	${WRKSRC}/apache2/${MODULENAME}.c

.include <bsd.port.mk>
