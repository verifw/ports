PORTNAME=	gettext
DISTVERSION=	1.6
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lua 5+ bindings for Gettext
WWW=		https://gitlab.com/ports1/lua-gettext

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext lua:51,module
USE_GITLAB=	yes
GL_ACCOUNT=	ports1
GL_PROJECT=	lua-gettext
GL_TAGNAME=	abd88932fc6e69b8955921bd0682b11db3102eca

MAKEFILE=	${FILESDIR}/Makefile
DOCS=	README README.md CHANGELOG
DOCSDIR=	${PREFIX}/share/doc/lua-${PORTNAME}
PLIST_FILES=	%%LUA_MODLIBDIR%%/lgettext.so \
		%%LUA_MODSHAREDIR%%/gettext.lua \
		%%DOCSDIR%%/README \
		%%DOCSDIR%%/README.md \
		%%DOCSDIR%%/CHANGELOG

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/gettext.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lgettext.so ${STAGEDIR}${LUA_MODLIBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${CP} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
