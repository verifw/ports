PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with ../thrift
PORTEPOCH=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	komarov@valerka.net
COMMENT=	Ruby interface to thrift
WWW=		https://thrift.apache.org/

LICENSE=	APACHE20

USES=		cpe gem
CPE_VENDOR=	apache

# Workaround for stage-qa:
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/ -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
