PORTNAME=	radmind
PORTVERSION=	1.15.4
PORTREVISION=	2021062801
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/voretaq7/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	Utility for administering filesystem changes
WWW=		https://github.com/voretaq7/radmind

LICENSE=	Michigan
LICENSE_NAME=	University of Michigan License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	gmake ssl
USE_RC_SUBR=	radmind

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-radminddir=${RADMIND_BASE_DIR}

CONFLICTS_INSTALL=	schilyutils # bin/fsdiff

MAKE_JOBS_UNSAFE=	yes

SUB_FILES+=	pkg-install pkg-message
SUB_LIST=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR} RADMINUSER=${RADMINUSER}

USERS=		${RADMINUSER}
GROUPS=		${RADMINUSER}

PLIST_SUB=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR:S@/@@} RADMINUSER=${RADMINUSER}

OPTIONS_DEFINE=	DOCS

DOCS=		COPYRIGHT SPEC README.md

RADMIND_BASE_DIR?=	${DESTDIR}/var/radmind
RADMINUSER=	radmind

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--enable-profiled=no
.endif

post-install:
	# Ugly hack to remove generated man pages
	${RM} -r ${WRKSRC}/tmp

	# Port's Docs (Copyright & wire protocol info)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/cert
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/client
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/command
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/file
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/postapply
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/preapply
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/special
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp/file
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp/transcript
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/transcript
	${CP}    ${FILESDIR}/config.sample ${STAGEDIR}${RADMIND_BASE_DIR}/config.sample

.include <bsd.port.mk>
