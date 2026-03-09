# Revisión de issues – ScanTailor-Advanced

Resumen de los [issues abiertos](https://github.com/ScanTailor-Advanced/scantailor-advanced/issues) del repositorio oficial, clasificados por si vale la pena considerarlos o no.

---

## Vale la pena considerar

### Bugs con impacto real

| # | Título | Motivo |
|---|--------|--------|
| **#30** | Exception while rendering output of dewarp | Bug grave y recurrente: `fillMarginsInPlace: the content area exceeds image rect`. Reproducible con dewarp manual + content box fuera de página; comentarios hasta 2025. Arreglar la excepción o capturarla en el hilo correcto. |
| **#20** | Large-format jpeg and png files can't be loaded | Bug en Windows: imágenes grandes no cargan (posible libjpeg/libpng en build). Confirmado en 1.0.19. Afecta a usuarios reales. |
| **#89** | Pick color (Fill zones) doesn't work when enable_opengl=true | Bug claro: Fill zones + OpenGL falla. Fácil de reproducir y acotar. |
| **#88** | "Insert before/after..." doesn't work when images already exist | Bug de flujo de trabajo; frustrante al añadir páginas a un proyecto existente. |
| **#90** | Content box position invalidated after manual split page offcut adjustment | Bug de consistencia: el contenido ajustado manualmente se pierde al tocar el offcut del split. |
| **#84** | Apply to... "This page and every other page" – erratic behaviour | Comportamiento errático en “aplicar a cada otra página”; hay comentarios de que empeora con otras opciones. |
| **#75** | Multi-Monitor context menu | Bug etiquetado: menú contextual en multi-monitor. |
| **#51** | Follow Page button behaviour | Bug etiquetado; afecta navegación. |
| **#98** | Cannot read JPG, reads TIFF (Git version) | Posible regresión/Quirks de Qt con JPG; workaround TIFF. Conviene verificar si sigue en master. |
| **#99** | Deterioration of display quality with fractional interface scaling | Calidad de interfaz con escalado fraccional (HiDPI); afecta usabilidad. |
| **#97** | Rendering issues with Wayland | Wayland es cada vez más común en Linux; merece atención. |

### Mejoras / features bien acotadas y alineadas con el proyecto

| # | Título | Motivo |
|---|--------|--------|
| **#64** | Provide valid Linux CI builds in Releases | Los DEB/RPM de CI no son válidos desde hace tiempo; se pide AppImage. Tu PR/CI ya toca este tema; puede cerrarse o referenciarse. |
| **#95** | Support Guideline on Margins view | El proyecto ya tiene “Guides” en Margins; esto podría ser extenderlo o aclarar doc. |
| **#93** | "Fix DPI" in Margins panel | Feature concreto: control de DPI en el panel de Márgenes. |
| **#52** | Resize pages to the same size (match size scaling) | Muy pedido: igualar tamaño entre páginas (ej. escáner en V). Hay interés y comparación con Experimental. |
| **#53** | Deskew: add oblique | Añadir corrección oblicua en deskew; hay comentario técnico (QTransform m21/m23). Relacionable con mejoras de deskew que ya tienes. |
| **#26** | Checkboxes for separate application of margins | Aplicar márgenes por página/grupo de forma selectiva; mejora de UX clara. |
| **#21** | Persistent zoom | Zoom que se mantenga al cambiar de página/pestaña; ya hay lógica similar para output tabs. |
| **#82** | Add guides to the output view | Guías también en la vista de salida; extensión natural de las guías actuales. |
| **#15** | Default zone creation mouse selection mode | Recordar modo de creación de zona (polígono/lasso/rectángulo). Pequeño y útil. |

### Infra / distribución

| # | Título | Motivo |
|---|--------|--------|
| **#37** | CI automation | Genérico pero alineado con tener CI estable y releases automatizadas. |
| **#105** | Flathub / Flatpak release | Flathub sigue empaquetando el original (4lex4); comentario indica que haría falta otro nombre/paquete. Decisión de mantenimiento/distribución. |
| **#61** | imageproc_tests fails when building offline in clean chroot | Build offline/chroot; importante para empaquetadores y CI en entornos restringidos. |

---

## Prioridad media (considerar más adelante)

| # | Título | Notas |
|---|--------|--------|
| **#92** | Fill outside page box (alternative to #91) | Alternativa más simple a #91; depende de si quieres priorizar relleno/offcut. |
| **#91** | Offcut lines in split pages | Más complejo; mejor si primero se hace #92 o se valida demanda. |
| **#81** | Freeze auto dewarping | Congelar resultado del auto-dewarp; útil para flujos avanzados. |
| **#86** | "Pause sorting pages" button | Pausar ordenación; mejora de UX en proyectos grandes. |
| **#85** | Split functionality of "Match size with other pages" | Refinar “Match size”; complementa #52. |
| **#74** | Content box alternate centering | Centrado alternativo del content box; enhancement acotado. |
| **#62** | Split Page doesn't work for Japanese books | Workaround: layout RTL; puede ser doc o pequeño fix. |
| **#67** | Selecting with frame (Ctrl) has disappeared | Comentario indica “Press C for RECTANGULAR” – posiblemente resuelto o tema de documentación. |
| **#2** | Extend selection in Select Content in a certain direction | Extender selección en una dirección; mejora de Select Content. |
| **#4** | Detection of page numbers and select content | Detección de números de página; más complejo, más “feature grande”. |

---

## No priorizar / descartar (por ahora)

| # | Título | Motivo |
|---|--------|--------|
| **#73** | Scan Tailor "Experimental" | Debate largo: fusión ST Experimental vs Advanced. Se concluye que la arquitectura es distinta; no es un issue implementable tal cual. Puede cerrarse como “discussion” o “wontfix”. |
| **#104** | Add scantailor-experimental features | Muy vago; sin especificación concreta. |
| **#103** | Output image pipe | Feature de integración (pipe); nicho y coste de diseño alto. |
| **#101** | WINDOWS 7 support | Windows 7 fuera de soporte; dependencias (Qt, etc.) tampoco lo soportan. Descatalogar. |
| **#96** | Any working example? | Pregunta sobre dewarp + OOM; más bien soporte / documentación; ya se enlaza a builds externos. |
| **#72** | Disabling content box | Poco definido; puede ser duplicado de “content box” en general. |
| **#49** | RIS | Formato RIS (citas bibliográficas); fuera del alcance de un procesador de imágenes. |
| **#43** | Examples? | Petición de ejemplos; comentario sugiere repo aparte `scantailor-advanced-demo`. No es bug ni feature de código. |
| **#42** | Website? | Cuestión de presencia web; no es issue de código. |
| **#27** | Repo visibility and next release | Mezcla visibilidad del repo e instalador; ya hay respuestas. Cerrar o dejar como referencia. |
| **#28** | Perspective correction tool | Enfoque tipo cámara / preproceso; se discute que hay otras herramientas. Alcance muy amplio. |
| **#22** | Beep when finished – alternate audio | Detalle de preferencia; prioridad baja. |
| **#12** | Partition foreground layer into regions with different threshold | Complejidad alta; más investigación necesaria. |
| **#10** | Cropping without processing | Cropping sin convertir; solapado con flujo actual y export. |
| **#5** | Export to indexed PNG with transparency | Exportación muy específica; prioridad baja. |
| **#13** | Feature request: type area | “Type area” sin definición clara. |
| **#25** | original alignment | Título solo; sin descripción. Cerrar o pedir detalles. |
| **#60** | Page size | Sin descripción; pedir contexto. |

---

## Resumen numérico

- **Vale la pena considerar:** ~25 issues (bugs importantes, features acotadas, CI/releases).
- **Prioridad media:** ~10 issues (útiles pero no urgentes).
- **No priorizar / descartar:** ~20 issues (vagos, fuera de alcance, duplicados, resueltos o de mantenimiento/documentación).

Recomendación: priorizar **#30** (dewarp), **#20** (imágenes grandes), **#89** (OpenGL + Fill zones), **#88** (Insert before/after) y **#64** (builds Linux/CI); luego **#52** (match size), **#53** (oblique), **#26** (márgenes por página) y **#21** (zoom persistente).
