PORTNAME=	stalonetray
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.5
CATEGORIES=	x11

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	STAnd-aLONE system tray
WWW=		https://kolbusa.github.io/stalonetray/

LICENSE=	GPLv2

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		libxslt>0:textproc/libxslt

USES=		autoreconf gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	kolbusa
USE_XORG=	sm ice x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-native-kde \
		--disable-debug

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stalonetrayrc.sample ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
