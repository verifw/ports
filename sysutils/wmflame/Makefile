PORTNAME=	wmflame
PORTVERSION=	0.60
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	AFTERSTEP/stable/rpms/misc-tarballs \
		http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that shows the load average as a flame
WWW=		http://web.novalis.org/

LICENSE=	GPLv2

USES=		gmake xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/wmflame

WRKSRC=		${WRKDIR}/wmflame.app/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmflame ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
