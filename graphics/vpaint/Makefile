PORTNAME=	vpaint
PORTVERSION=	1.7
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Experimental vector graphics and 2D animation editor
WWW=		https://www.vpaint.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dalboris

USES=		compiler:c++11-lib eigen:3 gl qmake qt:5
USE_QT=		core gui widgets opengl network qmake:build buildtools:build
USE_GL=		gl glu glew

QMAKE_SOURCE_PATH=	${WRKSRC}/src/Gui

CXXFLAGS+=	-isystem ${LOCALBASE}/include/eigen3

PORTDOCS=	*
PORTEXAMPLES=	*

DESKTOP_ENTRIES="VPaint" \
		"Vector-Based Animation Editor" \
		"VPaint" \
		"VPaint" \
		"Graphics;" \
		""

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${RM} -r ${WRKSRC}/src/Third

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/VPaint ${STAGEDIR}${PREFIX}/bin
.for s in 16 32 48 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}
	${INSTALL_DATA} ${WRKSRC}/src/Gui/images/icon-${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/VPaint.png
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.vec ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
