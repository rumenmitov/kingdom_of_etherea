{
  description = "Build steps for Kingdom of Etherea";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs   = nixpkgs.legacyPackages.${system};
    in
   {

     devShells.${system}.default   = import ./shell.nix { inherit pkgs; };
     packages.${system}.debug = import ./debug.nix { inherit pkgs; };
  };
}
