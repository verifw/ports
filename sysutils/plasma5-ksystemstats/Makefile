PORTNAME=	ksystemstats
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to report system activity
WWW=		https://invent.kde.org/plasma/ksystemstats

LIB_DEPENDS+=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kio libksysguard service \
		solid \
		ecm:build
USE_QT=		concurrent core dbus gui network \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
