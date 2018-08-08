#!/usr/bin/env bats

# dossier temporaire pour tests

mkdir -p "./tmp"
BATS_TMPDIR="./tmp"


@test "Programme par défault fonctionnel" {
	run bin/tp3
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Nom : Aruba" ]
}

@test "Mauvaise option" {
  run bin/tp3 -x
  [ "${lines[0]}" = "bin/tp3: invalid option -- 'x'" ]
}

@test "Option --show-country" {
	run bin/tp3 --country can
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Nom : Canada" ]
}

@test "Option --region europe" {
	run bin/tp3 --region europe
	[ "$status" -eq 0 ]
	[ "${lines[1]}" = "Code : ALA" ]	
}

@test "Option show-capital" {
	run bin/tp3 --show-capital
	[ "$status" -eq 0 ]
	[ "${lines[2]}" = "Capital: Oranjestad" ]
}

@test "Option show-borders" {
	run bin/tp3 --show-borders --country can
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Nom : Canada" ]
}


@test "Option show-languages" {
	run bin/tp3 --show-languages --region oceania
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Nom : American Samoa" ]
}