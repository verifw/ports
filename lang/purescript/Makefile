PORTNAME=	purescript
PORTVERSION=	0.15.9
CATEGORIES=	lang

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Functional language that compiles to JavaScript
WWW=		https://www.purescript.org/

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=	compiler crashes

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal

USE_LOCALE=	en_US.UTF-8

USE_CABAL=	Cabal-3.6.3.0 \
		Glob-0.10.2_3 \
		OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_1 \
		aeson-2.0.3.0_1 \
		aeson-better-errors-0.9.1.1_1 \
		alex-3.2.7.4 \
		ansi-terminal-0.11.5 \
		ansi-terminal-types-0.11.5_1 \
		ansi-wl-pprint-0.6.9_4 \
		assoc-1.0.2_4 \
		async-2.2.4_3 \
		attoparsec-0.14.4_3 \
		auto-update-0.1.6 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.9.0 \
		basement-0.0.15 \
		bifunctors-5.5.15 \
		bitvec-1.1.4.0 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_4 \
		bower-json-1.1.0.0 \
		boxes-0.1.5 \
		call-stack-0.4.0 \
		cborg-0.2.9.0 \
		cheapskate-0.1.1.2_1 \
		clock-0.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		conduit-extra-1.3.6 \
		constraints-0.13.4 \
		contravariant-1.5.5 \
		cryptonite-0.30 \
		css-text-0.1.3.0 \
		data-array-byte-0.1.0.1_1 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_4 \
		data-ordlist-0.4.7.0 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		easy-file-0.2.5 \
		edit-distance-0.2.2.1_1 \
		fast-logger-3.2.1 \
		file-embed-0.0.15.0 \
		free-5.2_1 \
		half-0.3.1 \
		happy-1.20.0_1 \
		hashable-1.4.2.0_1 \
		haskeline-0.8.2.1 \
		hsc2hs-0.68.9 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		invariant-0.6.1 \
		kan-extensions-5.2.5_1 \
		language-javascript-0.7.0.0 \
		lens-5.1.1_1 \
		lifted-async-0.10.2.4 \
		lifted-base-0.2.3.12 \
		memory-0.17.0_1 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.39_1 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		monoidal-containers-0.6.4.0 \
		mtl-compat-0.2.2 \
		network-3.1.3.0 \
		network-uri-2.6.4.2 \
		newtype-0.2.2.0_3 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optparse-applicative-0.17.0.0 \
		parallel-3.2.2.0_6 \
		pattern-arrows-0.0.2_1 \
		primitive-0.7.4.0_1 \
		process-1.6.13.1_1 \
		profunctors-5.6.2_3 \
		protolude-0.3.3 \
		random-1.2.1.1 \
		reflection-2.1.7 \
		regex-base-0.94.0.2_1 \
		regex-tdfa-1.3.2 \
		resourcet-1.3.0 \
		safe-0.3.19 \
		scientific-0.3.7.0_5 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7_1 \
		semigroups-0.20 \
		serialise-0.2.6.0_3 \
		sourcemap-0.1.7 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		stm-chans-3.0.0.9 \
		streaming-commons-0.2.2.6 \
		strict-0.4.0.1_4 \
		stringsearch-0.3.6.6_1 \
		syb-0.7.2.3 \
		tagged-0.8.7 \
		tagsoup-0.14.8 \
		text-short-0.1.5_2 \
		th-abstraction-0.4.5.0_1 \
		th-compat-0.1.4_2 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_5 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_5 \
		typed-process-0.2.11.0 \
		uniplate-1.6.13_1 \
		unix-compat-0.7 \
		unix-time-0.4.9 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_4 \
		vector-0.12.3.1_4 \
		vector-algorithms-0.9.0.1_2 \
		void-0.7.3 \
		witherable-0.4.2_4 \
		xss-sanitize-0.3.7.2 \
		zlib-0.6.3.0_1

CABAL_EXECUTABLES=	purs
CABAL_FLAGS=		release

.include <bsd.port.mk>
