PORTNAME=	peek-rblineprof
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Peek into how much each line of your Rails application takes
WWW=		https://github.com/peek/peek-rblineprof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-peek-rails52>=0:devel/rubygem-peek-rails52 \
		rubygem-rblineprof>=0:devel/rubygem-rblineprof

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
