{ pkgs ? import <nixpkgs> }:
pkgs.stdenv.mkDerivation {
  name = "Kingdom of Etherea (debug)";
  src  = ./.;

  buildInputs = with pkgs; [ SDL2 ];

  buildPhase = "make debug";

  installPhase = ''
		    mkdir -p $out/bin
        cp -r bin/* $out/bin
	      $out/bin/debug/main
      '';
}
