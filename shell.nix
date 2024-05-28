{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ SDL2 SDL2_image ];

  shellHook = ''
			emacs &
            disown
            exit
    '';
}
