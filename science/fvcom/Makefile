PORTNAME=	fvcom
PORTVERSION=	2.7.1
PORTREVISION?=	18
CATEGORIES=	science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/index.html/
DISTNAME=	sourcecode1
DIST_SUBDIR=	fvcom

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unstructured Grid Finite Volume Coastal Ocean Model
WWW=		http://fvcom.smast.umassd.edu/FVCOM/index.html

# Converted from RESTRICTED
LICENSE=	fvcom
LICENSE_NAME=	fvcom
LICENSE_TEXT=	Requires (free) registration
LICENSE_PERMS=	auto-accept

# Check netcdf lib for Fortran support!
LIB_DEPENDS+=	libnetcdff.so:science/netcdf-fortran \
		liblapack.so:math/lapack \
		libblas.so:math/lapack

USES=		fortran
USE_GCC=	yes
WRKSRC=		${WRKDIR}/FVCOM2.7.1/FVCOM_source

PLIST_FILES=	${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

MAKE_JOBS_UNSAFE=	yes

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' \
		${WRKDIR}/FVCOM2.7.1/METIS_source/makefile
	${REINPLACE_CMD} -e 's|cpp|${CPP}|g' \
		${WRKDIR}/FVCOM2.7.1/FVCOM_source/Makefile

pre-build:
	(cd ${WRKSRC}/../METIS_source && make)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${MPIPREFIX}bin
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom \
		${STAGEDIR}${PREFIX}/${MPIPREFIX}bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
