#include "faest.inc"

namespace faest
{

// clang-format off

template bool faest_unpack_secret_key(secret_key<v1::faest_128_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_128_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_192_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_192_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_256_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_256_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_128_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_128_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_192_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_192_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_256_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v1::faest_em_256_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_128_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_128_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_192_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_192_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_256_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_256_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_128_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_128_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_192_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_192_f>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_256_s>*, const uint8_t*);
template bool faest_unpack_secret_key(secret_key<v2::faest_em_256_f>*, const uint8_t*);

template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_128_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_128_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_192_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_192_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_256_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_256_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_128_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_128_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_192_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_192_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_256_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v1::faest_em_256_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_128_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_128_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_192_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_192_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_256_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_256_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_128_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_128_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_192_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_192_f>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_256_s>*);
template void faest_pack_public_key(uint8_t*, const public_key<v2::faest_em_256_f>*);

template void faest_unpack_public_key(public_key<v1::faest_128_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_128_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_192_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_192_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_256_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_256_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_128_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_128_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_192_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_192_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_256_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v1::faest_em_256_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_128_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_128_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_192_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_192_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_256_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_256_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_128_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_128_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_192_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_192_f>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_256_s>*, const uint8_t*);
template void faest_unpack_public_key(public_key<v2::faest_em_256_f>*, const uint8_t*);

template bool faest_pubkey<v1::faest_128_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_128_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_192_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_192_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_256_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_256_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_128_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_128_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_192_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_192_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_256_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v1::faest_em_256_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_128_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_128_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_192_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_192_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_256_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_256_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_128_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_128_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_192_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_192_f>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_256_s>(uint8_t*, const uint8_t*);
template bool faest_pubkey<v2::faest_em_256_f>(uint8_t*, const uint8_t*);

template bool faest_sign<v1::faest_128_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_128_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_192_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_192_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_256_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_256_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_128_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_128_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_192_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_192_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_256_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v1::faest_em_256_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_128_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_128_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_192_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_192_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_256_s>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_256_f>( uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_128_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_128_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_192_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_192_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_256_s>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);
template bool faest_sign<v2::faest_em_256_f>(uint8_t*, const uint8_t*, size_t, const uint8_t*, const uint8_t*, size_t);

template bool faest_verify<v1::faest_128_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_128_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_192_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_192_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_256_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_256_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_128_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_128_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_192_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_192_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_256_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v1::faest_em_256_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_128_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_128_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_192_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_192_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_256_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_256_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_128_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_128_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_192_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_192_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_256_s>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);
template bool faest_verify<v2::faest_em_256_f>(const uint8_t*, const uint8_t*, size_t, const uint8_t*);

// clang-format on

} // namespace faest
