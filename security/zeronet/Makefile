PORTNAME=	zeronet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	security net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Decentralized websites using Bitcoin crypto and BitTorrent network
WWW=		https://zeronet.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coincurve>0:security/py-coincurve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>0:www/py-gevent-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maxminddb>0:net/py-maxminddb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}merkletools>0:security/py-merkletools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelliptic>0:security/py-pyelliptic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-bitcoinlib>0:finance/py-python-bitcoinlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>0:security/py-rsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>0:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

SUB_FILES=	zeronet-service zeronet-cmd pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} USER=${USER} GROUP=${GROUP}
PLIST_SUB=	USER=${USER} GROUP=${GROUP}

# ZeroNet hasn't been ported to Python 3 yet
# https://github.com/HelloZeroNet/ZeroNet/issues/149
USES=		python shebangfix
SHEBANG_FILES=	zeronet.py
USE_GITHUB=	yes
GH_ACCOUNT=	HelloZeroNet
GH_PROJECT=	ZeroNet
NO_ARCH=	yes

OPTIONS_DEFINE=	DEBUG

DEBUG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}

.include <bsd.port.options.mk>

USER=		nobody
GROUP=		nobody

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|msgpack-python|msgpack|' ${WRKSRC}/requirements.txt

do-build:
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC}
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}/
	@${RM} `${FIND} ${STAGEDIR}${DATADIR} -name "*.orig"`
	@${RM} `${FIND} ${STAGEDIR}${DATADIR} -name LICENSE`
	@${RM} ${STAGEDIR}${DATADIR}/README*.md ${STAGEDIR}${DATADIR}/CHANGELOG*.md ${STAGEDIR}${DATADIR}/requirements.txt
	@${RM} ${STAGEDIR}${DATADIR}/Vagrantfile ${STAGEDIR}${DATADIR}/Dockerfile
	@${RM} -r `${FIND} ${STAGEDIR}${DATADIR} -name test`
	@${MKDIR} ${STAGEDIR}/var/db/zeronet
	@${MKDIR} ${STAGEDIR}/var/log/zeronet
	@${LN} -s /var/db/zeronet ${STAGEDIR}${DATADIR}/data
	@${LN} -s /var/log/zeronet ${STAGEDIR}${DATADIR}/log
	@${LN} -s /var/db/zeronet/zeronet.conf ${STAGEDIR}${DATADIR}/zeronet.conf # ZeroNet writes this file when it is used w/out the 'tor' option
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-cmd ${STAGEDIR}${PREFIX}/bin/zeronet
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-service ${STAGEDIR}${PREFIX}/etc/rc.d/zeronet

.include <bsd.port.mk>
