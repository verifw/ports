PORTNAME=	mod_webkit
PORTVERSION=	1.2.3
CATEGORIES=	www

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for WebWare WebKit AppServer
WWW=		https://cito.github.io/w4py/

LICENSE=	PSFL

USE_GITHUB=	yes
GH_ACCOUNT=	Cito
GH_PROJECT=	w4py

USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS=	marshal.c

WRKSRC_SUBDIR=		WebKit/Adapters/${PORTNAME}2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
