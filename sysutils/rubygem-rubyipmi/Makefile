PORTNAME=	rubyipmi
PORTVERSION=	0.11.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Command line wrapper for ipmitool and freeipmi
WWW=		https://github.com/logicminds/rubyipmi

LICENSE=	LGPL21

RUN_DEPENDS=	${LOCALBASE}/sbin/bmc-device:sysutils/freeipmi \
		rubygem-highline>=0:devel/rubygem-highline

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
