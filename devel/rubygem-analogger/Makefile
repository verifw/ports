PORTNAME=	analogger
PORTVERSION=	1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, flexible, easy to use logging service for Ruby
WWW=		https://github.com/wyhaines/analogger

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=1.2.5:devel/rubygem-eventmachine

NO_ARCH=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/analogger

SHEBANG_FILES=	bin/analogger
ruby_OLD_CMD=	ruby

.include <bsd.port.mk>
