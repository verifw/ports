PORTNAME=	unleash
PORTVERSION=	3.2.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client for Unleash
WWW=		https://github.com/unleash/unleash-client-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-murmurhash3>=0.1.6<0.2.0:devel/rubygem-murmurhash3

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/unleash-client

.include <bsd.port.mk>
