PORTNAME=	prodigal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.3-16
DISTVERSIONSUFFIX=	-gc1e2d36
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protein-coding gene prediction for prokaryotic genomes
WWW=		https://github.com/hyattpd/Prodigal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	hyattpd
GH_PROJECT=	Prodigal

BINARY_ALIAS=	gcc=${CC}
MAKE_ARGS=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	skipv:2.60 # a very old version is labeled with 2.60 in their repository

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
