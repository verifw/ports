PORTNAME=	libkexiv2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE
WWW=		https://www.digikam.org/

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core gui \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
