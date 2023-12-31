PORTNAME=	atheme-services
PORTVERSION=	7.2.12
CATEGORIES=	irc net
MASTER_SITES=	https://github.com/atheme/atheme/releases/download/v${PORTVERSION}/
DISTNAME=	atheme-services-v${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Set of services for IRC networks
WWW=		https://atheme.github.io/atheme.html

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmowgli-2.so:devel/libmowgli2

USES=		cpe gmake localbase pathfix pkgconfig ssl tar:xz
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fhs-paths \
		--sysconfdir=${PREFIX}/etc/atheme \
		--localstatedir=/var \
		--disable-gtk-doc \
		--enable-large-net

CPE_PRODUCT=	atheme

CONFLICTS_INSTALL=	lifelines

USERS=		ircservices
GROUPS=		ircservices

USE_RC_SUBR=	atheme-services

OPTIONS_DEFINE=	CONTRIB CRACKLIB DOCS LDAP NLS PCRE PERL
OPTIONS_DEFAULT=	CRACKLIB LDAP PCRE PERL

CONTRIB_DESC=	Enable contrib modules
CRACKLIB_DESC=	Use cracklib for checking password strength

OPTIONS_SUB=	yes

CONTRIB_CONFIGURE_ENABLE=	contrib
CRACKLIB_LIB_DEPENDS=	libcrack.so:security/cracklib
CRACKLIB_CONFIGURE_WITH=	cracklib
LDAP_USES=	ldap
LDAP_CONFIGURE_WITH=	ldap
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre
PERL_USES=	perl5
PERL_CONFIGURE_WITH=	perl

.include <bsd.port.mk>
