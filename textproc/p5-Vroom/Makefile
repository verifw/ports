PORTNAME=	Vroom
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Slide Shows in Vim
WWW=		https://metacpan.org/release/Vroom

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-Template-Toolkit-Simple>=0:www/p5-Template-Toolkit-Simple \
		p5-Term-Size>=0:devel/p5-Term-Size \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
