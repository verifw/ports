PORTNAME=	libmpdclient
PORTVERSION=	2.20
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API library for interfacing MPD
WWW=		https://www.musicpd.org/libs/libmpdclient/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson tar:xz

MESON_ARGS=	--default-library=both
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_TRUE=	documentation

.include <bsd.port.mk>
