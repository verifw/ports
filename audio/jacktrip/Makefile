PORTNAME=	jacktrip
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-beta1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-machine audio network performance over the Internet
WWW=		https://github.com/jacktrip/jacktrip

LICENSE=	MIT GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libjack.so:audio/jack \
		librtaudio.so:audio/rtaudio

USES=		meson compiler:c++17-lang gl pkgconfig qt:6
USE_QT=		base declarative svg webengine websockets
USE_GL=		gl

USE_GITHUB=	yes
GH_TUPLE=	jacktrip:Simple-FFT:06f237780364879337750d1ac9f3b000b4b7a160:jacktrip_Simple_FFT/externals/Simple-FFT \
		x42:weakjack:cddbeec0953d68048d164c472c9b30a5d96778db:x42_weakjack/externals/weakjack


#CXXFLAGS+=	`pkg-config --cflags rtaudio`
#LDFLAGS+=	`pkg-config --libs rtaudio`

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
