PORTNAME=	gtksourceview
PORTVERSION=	5.4.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	5
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget
WWW=		https://wiki.gnome.org/Projects/GtkSourceView

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libpcre2-8.so:devel/pcre2

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz vala:build
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
