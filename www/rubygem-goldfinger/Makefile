PORTNAME=	goldfinger
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Webfinger utility for Ruby
WWW=		https://github.com/tootsuite/goldfinger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5<3:www/rubygem-addressable \
		rubygem-http4>=4.0<5:www/rubygem-http4 \
		rubygem-nokogiri>=1.8<2:textproc/rubygem-nokogiri \
		rubygem-oj>=3.0<4:devel/rubygem-oj

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
