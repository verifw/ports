PORTNAME=	nfs-over-tls
DISTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~rmacklem/nfs-over-tls/

MAINTAINER=	rmacklem@freebsd.org
COMMENT=	Utilities for NFS over TLS
WWW=		https://people.freebsd.org/~rmacklem/nfs-over-tls-setup.txt

LICENSE=	BSD2CLAUSE

IGNORE_FreeBSD_12=requires FreeBSD 13 or later with in-kernel TLS support \
		and OpenSSL with KTLS enabled

LIB_DEPENDS=	libssl.so:security/openssl

USES=		kmod ssl

.if exists(/usr/sbin/rpc.tlsclntd)
IGNORE=		already included in the base system
.endif

.include <bsd.port.mk>
