PORTNAME=	Net-APNs-Extended
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for APNs that support the extended format
WWW=		https://metacpan.org/release/Net-APNs-Extended

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-JSON-XS>0:converters/p5-JSON-XS \
	p5-Net-SSLeay>0:security/p5-Net-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
