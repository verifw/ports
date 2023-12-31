PORTNAME=	xephem
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	astro

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive astronomical ephemeris program
WWW=		http://www.clearskyinstitute.com/xephem/xephem.html

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/XEphem-${PORTVERSION}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake groff jpeg motif tar:tgz ssl xorg
USE_XORG=	xt xext xmu x11 xft

USE_GITHUB=	yes
GH_PROJECT=	XEphem

LDFLAGS+=	-lfontconfig

WRKSRC_SUBDIR=	GUI/xephem

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC}/../.. -name Makefile -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's|CC = gcc|CC?= ${CC}|g ; \
		s|CFLAGS =|CFLAGS+=|g ; \
		s|LDFLAGS =|LDFLAGS+=|g ; \
		s|-O2 ||g'

pre-build:
	@${ECHO_CMD} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' \
		> ${WRKSRC}/XEphem.ad

pre-install:
	@${FIND} ${WRKSRC}/../.. -name Makefile.bak -type f -delete
	@${CP} ${WRKSRC}/xephem.man ${STAGEDIR}${PREFIX}/man/man1/xephem.1
	@${FIND} ${WRKSRC} -name "*.pl" -exec ${SED} -i "" -e 's|/usr/bin/perl|/usr/local/bin/perl|' {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XEphem
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xephem
	@cd ${WRKSRC}; ${COPYTREE_SHARE} \
		"auxil catalogs fifos fits gallery help lo" \
		${STAGEDIR}${PREFIX}/lib/X11/xephem

.include <bsd.port.mk>
