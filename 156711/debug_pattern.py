#!/usr/bin/env python3

print("🔍 DEBUG: Analisando padrão de comparação...")

# Lê as quadruplas
with open("intermediate_output.txt", "r") as f:
    lines = f.readlines()

# Remove cabeçalhos
quads = []
for line in lines:
    line = line.strip()
    if line.startswith("(") and line.endswith(")"):
        # Parse (op,arg1,arg2,arg3)
        content = line[1:-1]  # Remove parênteses
        parts = content.split(",")
        if len(parts) == 4:
            quad = {
                "op": parts[0].strip(),
                "arg1": parts[1].strip(),
                "arg2": parts[2].strip(),
                "arg3": parts[3].strip(),
            }
            quads.append(quad)

print(f"📊 Total de quadruplas: {len(quads)}")

# Procura pelo padrão específico
for i in range(len(quads) - 1):
    current = quads[i]
    next_quad = quads[i + 1]

    print(f"\n🔎 Quadrupla {i}: {current}")
    print(f"🔎 Quadrupla {i+1}: {next_quad}")

    # Verifica se current é comparação
    if current["op"] in ["==", "!=", ">", ">=", "<", "<="]:
        print(f"   ✅ {current['op']} é operação de comparação")

        # Verifica se next é if_t ou if_f
        if next_quad["op"] in ["if_t", "if_f"]:
            print(f"   ✅ {next_quad['op']} é operação condicional")

            # Verifica se resultado da comparação é usado na condição
            if current["arg3"] == next_quad["arg1"]:
                print(f"   ✅ Resultado {current['arg3']} usado em {next_quad['arg1']}")

                if current["op"] == "==" and next_quad["op"] == "if_f":
                    print(f"   🎯 PADRÃO DETECTADO: == + if_f (linha {i+1}-{i+2})")
                    print(
                        f"      Deveria ser: BNE {current['arg1']}, R0, {next_quad['arg2']}"
                    )
                    print(f"      Atual arg2: {current['arg2']}")

                    # Verifica se arg2 é t0 com valor 0
                    if current["arg2"] == "t0":
                        # Procura onde t0 foi definido
                        for j in range(i):
                            if quads[j]["op"] == "immed" and quads[j]["arg3"] == "t0":
                                print(
                                    f"      🔍 t0 definido na linha {j+1}: immed,{quads[j]['arg1']}"
                                )
                                if quads[j]["arg1"] == "0":
                                    print(f"      ✅ t0 contém 0 - deveria usar R0!")
                                break
            else:
                print(
                    f"   ❌ Resultado {current['arg3']} != argumento {next_quad['arg1']}"
                )
        else:
            print(f"   ❌ {next_quad['op']} não é operação condicional")
    else:
        print(f"   ❌ {current['op']} não é operação de comparação")

print("\n🎯 DEBUG CONCLUÍDO!")
