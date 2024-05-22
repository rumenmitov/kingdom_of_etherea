{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ SDL2 ];

  shellHook = ''
			emacs
    '';
}
