PORTNAME=	ortp
DISTVERSION=	5.2.94
CATEGORIES=	net

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library
WWW=		https://www.linphone.org/technical-corner/ortp.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c11
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_DOC=NO -DENABLE_STATIC=NO -DENABLE_STRICT=NO \
			-DCMAKE_PREFIX_PATH=${LOCALBASE}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
