PORTNAME=	opensearch-dashboards
DISTVERSION=	2.9.0
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.opensearch.org/releases/bundle/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	opensearch@FreeBSD.org
COMMENT=	Visualization dashboards for OpenSearch
WWW=		https://opensearch.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	npm-node18>0:www/npm-node18

USES=		nodejs:18,build,run python:build
USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	CHROME

CHROME_DESC=	Add dependency on www/chromium (required for PDF reports)
CHROME_RUN_DEPENDS=chrome:www/chromium

NODE_VER=	18.16.1

_DEVDIR=	${WRKDIR}/.devdir

post-patch:
	@${REINPLACE_CMD} -e 's|14.20.1|${NODE_VER}|g' ${WRKSRC}/package.json
	${RM} \
		${WRKSRC}/bin/*.orig \
		${WRKSRC}/bin/*.bak \
		${WRKSRC}/package.json.bak
	${RM} -r ${WRKSRC}/plugins/reportsDashboards/.chromium

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/opensearch_dashboards.yml ${STAGEDIR}${ETCDIR}/opensearch_dashboards.yml.sample
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "data node_modules package.json plugins src" ${STAGEDIR}${WWWDIR} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR})

post-install:
	${ECHO} "@sample ${ETCDIR}/opensearch_dashboards.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(www,www) ${WWWDIR}/data" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/legacy" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/fixed" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/test/resources/dynamic" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/examples/fixed" >> ${TMPPLIST}
	${ECHO} "@dir ${WWWDIR}/plugins/reportsDashboards/node_modules/set-interval-async/examples/dynamic" >> ${TMPPLIST}

.include <bsd.port.mk>
